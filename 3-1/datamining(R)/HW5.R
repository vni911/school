#22110670 김정운
setwd("C:/Users/0911k/Desktop/데이터마아닝/HW5")
data <- read.csv("Job_offer_data.csv", header = TRUE)
colnames(data) <-c("X1", "X2", "X3", "X4", "Y")
data_model = glm(Y ~ X1 + X2 + X3 + X4, family='binomial', data = data)
data_model

#Q2
vif(data_model)

#Q3
summary(data_model)