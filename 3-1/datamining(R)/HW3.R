##22110670 김정운


setwd("C:/Users/0911k/Desktop/데이터마아닝/HW3")

data <- read.csv("monthly_expenses.csv", header = TRUE)

#Q1
colnames(data) <- c("X1", "X2", "X3", "X4", "Y")

data_lm = lm(Y ~ X1 + X2 + X3 + X4, data = data)
data_lm


#Q2
data_X1 <- summary(lm(X1 ~ X2 + X3 + X4, data = data))
data_X2 <- summary(lm(X2 ~ X1 + X3 + X4, data = data))
data_X3 <- summary(lm(X3 ~ X1 + X2 + X4, data = data))
data_X4 <- summary(lm(X4 ~ X1 + X2 + X3, data = data))
data_X1$r.squared
data_X2$r.squared
data_X3$r.squared
data_X4$r.squared

#Q3 전체 F 검정
Predict_data <- function(X1,X2,X3,X4){
  Y_hat<- 57.21 + 0.20*X1 + 0.81*X2 + 1.42*X3 + 1.73*X4
  return(Y_hat)
}
Predict_data(X1=data$X1, X2=data$X2, X3=data$X3, X4=data$X4)

data_Y_hat <- predict(data_lm)
data_SST <- sum((data$Y - mean(data$Y))^2)
data_SSE <- sum((data$Y - data_Y_hat)^2)
data_SSR <- sum((data_Y_hat - mean(data$Y))^2)
data_SST
data_SSE
data_SSR
anova(data_lm)
summary(data_lm)

#Q3 개별 t-검정
confint(data_lm)