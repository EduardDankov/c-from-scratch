pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Build') {
            steps {
                script {
                    try {
                        sh 'make'
                        archiveArtifacts artifacts: 'build/bin/*', fingerprint: true
                    } catch (Exception e) {
                        error "Build failed. Check the logs for details."
                    }
                }
            }
        }
        stage('Test') {
            steps {
                script {
                    try {
                        sh 'chmod +x build/bin/*'
                        sh './build/bin/c-from-scratch'
                    } catch (Exception e) {
                        error "Tests failed. Check the logs for details."
                    }
                }
            }
        }
    }

    post {
        success {
            echo 'Build completed successfully.'
        }
        failure {
            echo 'Build failed. Check the logs for details.'
        }
    }
}
