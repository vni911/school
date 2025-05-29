## (1)
library(MASS)
data("Boston")
set.seed(123)
Boston$high_price <- ifelse(Boston$medv > mean(Boston$medv), 1, 0)

K <- 5
n <- nrow(Boston)
folds <- sample(rep(1:K, length.out = n))

error_M1 <- rep(NA, K)
error_M2 <- rep(NA, K)
error_M3 <- rep(NA, K)

for (i in 1:K) {
  val_idx <- which(folds == i)
  train_data <- Boston[-val_idx, ]
  val_data <- Boston[val_idx, ]
  
  # high_price ~ crim
  model1 <- glm(high_price ~ crim, data = train_data, family = binomial)
  pred1 <- ifelse(predict(model1, newdata = val_data, type = "response") > 0.5, 1, 0)
  error_M1[i] <- mean(pred1 != val_data$high_price)
  
  # high_price ~ ptratio
  model2 <- glm(high_price ~ ptratio, data = train_data, family = binomial)
  pred2 <- ifelse(predict(model2, newdata = val_data, type = "response") > 0.5, 1, 0)
  error_M2[i] <- mean(pred2 != val_data$high_price)
  
  # high_price ~ tax
  model3 <- glm(high_price ~ tax, data = train_data, family = binomial)
  pred3 <- ifelse(predict(model3, newdata = val_data, type = "response") > 0.5, 1, 0)
  error_M3[i] <- mean(pred3 != val_data$high_price)
}

mean_error_M1 <- mean(error_M1)
mean_error_M2 <- mean(error_M2)
mean_error_M3 <- mean(error_M3)

cat("Model 1 (high_price ~ crim):", round(mean_error_M1, 4), "\n")
cat("Model 2 (high_price ~ ptratio):", round(mean_error_M2, 4), "\n")
cat("Model 3 (high_price ~ tax):", round(mean_error_M3, 4), "\n")


## (2)
TP <- sum(pred2 == 1 &  val_data$high_price == 1)
FP <- sum(pred2 == 1 &  val_data$high_price == 0)
TN <- sum(pred2 == 0 & val_data$high_price == 0)
FN <- sum(pred2 == 0 &  val_data$high_price == 1)

# 지표 계산
accuracy <- (TP + TN) / (TP + TN + FP + FN)
recall <- TP / (TP + FN)
specificity <- TN / (TN + FP)
precision <- TP / (TP + FP)
f1_score <- 2 * precision * recall / (precision + recall)

cat("Accuracy    : ", accuracy, "\n")
cat("Sensitivity : ", recall, "\n")
cat("Specificity : ", specificity, "\n")
cat("Precision   : ", precision, "\n")
cat("F1 Score    : ", f1_score, "\n")