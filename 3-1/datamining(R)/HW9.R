rm(list=)
library(ISLR)
library(bestglm)

data(Hitters)
Hitters <- na.omit(Hitters)

hitters_data <- Hitters[, c("AtBat", "Hits", "HmRun", "Runs", "RBI",
                            "Walks", "Years", "CAtBat", "CHits", "CRuns", "Salary")]

#AIC
best_model_aic <- bestglm(hitters_data, family = gaussian, IC = "AIC",
                          method = "exhaustive")


 
best_model_aic$Subsets   
best_model_aic$Subsets$AIC

summary(best_model_aic$BestModel)


aic_values = best_model_aic$Subsets$AIC


# Plot AIC
plot(num_vars_aic, aic_values, type = "b", pch = 19,
     xlab = "Number of Variables", ylab = "AIC",
     main = "AIC by Model Size (Forward Selection)")
best_aic_index = which.min(aic_values)
best_aic_index
points(best_aic_index, aic_values[best_aic_index], col = "blue", cex = 2, pch = 19)



# 2) BIC
best_model_exhaustive_bic = bestglm(Xy = hitters_data, family = gaussian, IC = "BIC", method = "exhaustive")

best_model_exhaustive_bic$Subsets

best_model_exhaustive_bic$Subsets$BIC
bic_values_exh = best_model_exhaustive_bic$Subsets$BIC
num_vars_bic_exh = c(1:length(bic_values_exh))

# Plot BIC
plot(num_vars_bic_exh, bic_values_exh, type = "b", pch = 19,
     xlab = "Number of Variables", ylab = "BIC",
     main = "BIC by Model Size (Exhaustive Search)")
best_bic_index_exh = which.min(bic_values_exh)
best_bic_index_exh

points(best_bic_index_exh, bic_values_exh[best_bic_index_exh], col = "red", cex = 2, pch = 19)

# View best model summary according to BIC
summary(best_model_exhaustive_bic$BestModel)


