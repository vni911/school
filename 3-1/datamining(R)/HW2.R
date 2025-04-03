setwd("C:/Users/0911k/Desktop/데이터마아닝")

data <- read.csv("HW2_data.csv", header = TRUE)

#Q1
plot(data, col='red', main = "22110670 김정운")

#Q2
lm(data$Exam_Score ~ data$Study_Hours)

#Q3
anova(lm(data$Exam_Score ~ data$Study_Hours))

#Q4
summary(lm(data$Exam_Score ~ data$Study_Hours))
