#22110670 김정운

#Q1.
c(seq(2,8,2), rep(3,5))

#Q2. 
3*(2*pi-1)+1

#Q3.
q3_func <- function(k){
  y=2*k
  return(y)
}
q3_func(k=3)

#Q4.
q4_func <- function(X){
  y=sum(X)-5
  return(y)
}
X<-c(1,2,3,4,5)
q4_func(X)

#Q5.
D = matrix(c(10,1, 5, 15, 6, 6), ncol=2, byrow=TRUE)
D

#Q6.
D = matrix(c(10,1, 5, 15, 6, 6), ncol=2, byrow=TRUE)
colnames(D) <- c("Yes", "No")
rownames(D) <- c("Soccer", "Baseball", "Basketball")
D

#Q7
A = matrix(c(1,2,3,10,20,30), ncol=3, byrow=TRUE)
B = matrix(c(-1,-2,-3,-10,-20,-30), ncol=3, byrow=TRUE)
C = matrix(c(0,1,1,0,0,1), ncol=2, byrow=TRUE)
#Q7. 1)
A+B
#Q7. 2)
A*B
#Q7, 3)
A%*%C

#Q8
ID <- c(1,2,3,4,5)
gender <- c("F","M","M","F","M")
age <- c(20, 31, 20, 22, 24)
sports <- c("Basketball","Soccer", "Baseball", "Soccer", "Baseball")
dat <- data.frame(ID=ID, Gender=gender, Age=age, Sports=sports)
dat

#Q9
hist(dat$Age,xlab="Age",ylab="Frequency", main = "연령", col="lightgreen")
