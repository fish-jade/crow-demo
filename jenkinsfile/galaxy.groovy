def url = 'git@gitlab.gz.cvte.cn:1602/client/aoip/galaxy.git'
def branch = "${BRANCH}"
def tag = ""
def build_image = 'registry.gz.cvte.cn/1602/aoip-ubuntu:1.0.0'
def docker_registry = 'https://registry.gz.cvte.cn'

pipeline {
    agent {
        label "1602-sfu"
    }
    stages {
        stage('Checkout') {
            steps {
                cleanWs()
                checkout([$class: 'GitSCM', branches: [[name: branch]], userRemoteConfigs: [[credentialsId: 'mh1602', url: url]]])
            }
        }

        stage('Build') {
            steps {
                script {
                    echo "docker构建开始：${branch}"
                    withDockerRegistry([credentialsId: '6e5c1650-13f9-435e-ad7e-c0a20d0774a1', url: "${docker_registry}"]) {
                        docker.image(build_image).inside("-u root") {
                            sh '''
                                mkdir build
                                cd build
                                conan install .. -pr=rc-build-root --build missing -s build_type=Release
                                cmake .. -DCMAKE_BUILD_TYPE=Release --preset conan-release
                                cd Release
                                make
                            '''
                        }
                    }
                    echo "docker构建结束：${branch}"
                    // 创建构建完成标记
                    sh "touch ${WORKSPACE}/build/.build_complete"
                }
            }
        }

        stage('Package and Upload') {
            steps {
                script {
                    def buildDir = "${WORKSPACE}/build/Release"
                    def buildCompleteMarker = "${WORKSPACE}/build/.build_complete"
                    
                    // 检查构建是否完成
                    if (!fileExists(buildCompleteMarker)) {
                        error "构建完成标记文件不存在，构建可能未正常完成"
                    }
                    
                    // 检查构建目录是否存在
                    if (!fileExists(buildDir)) {
                        error "构建目录 ${buildDir} 不存在，构建可能失败"
                    }
                    
                    // 检查构建产物是否存在（假设主要产物名为 'galaxy'）
                    if (!fileExists("${buildDir}/galaxy")) {
                        error "构建产物 'galaxy' 不存在，构建可能失败"
                    }

                    def timestamp = new Date().format('yyyyMMdd_HHmmss')
                    def tar_name = "galaxy_${branch}_${timestamp}.tar.gz"

                    // 打包 Release 目录
                    sh "tar -czf ${tar_name} -C ${buildDir} ."

                    // 上传到私有化仓库
                    withCredentials([usernamePassword(credentialsId: 'artifactory-credentials', usernameVariable: 'ARTIFACTORY_USER', passwordVariable: 'ARTIFACTORY_PASS')]) {
                        sh """
                            curl -uzhangyong1924:AP8genobRHGk28aMVufLNonDeCuZVQXr2gwk1Z -T ${tar_name} \
                            "https://artifactory.gz.cvte.cn/artifactory/binaries/1602/private-be/aoip/${tar_name}"
                        """.replace("\n","")
                    }
                    // 清理临时文件
                    sh "rm ${tar_name}"
                }
            }
        }
    }

    post {
        always {
            cleanWs()
        }
    }
}