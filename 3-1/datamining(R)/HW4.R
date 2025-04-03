#22110670 김정운
setwd("C:/Users/0911k/Desktop/데이터마아닝/HW4")
data <- read.csv("HW4_data.csv", header = TRUE)
colnames(data) <-c("Y", "X")

#Q2
#(1)
data_model <- glm(Y~X, family="binomial", data = data)
data_model
exp(coef(data_model))

#(2)
summary(data_model)