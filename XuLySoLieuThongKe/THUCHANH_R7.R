#---- Lựa chọn mô hình ----
# ---- Hồi quy từng bước ----
## syntax: regsubsets(x = ..., data = ..., weights = NULL, nvmax = 8,
# method = c("exhaustive", "backward", "forward", "seqrep"))

library(tidyverse)
library(leaps)

data(Hitters, package = "ISLR2")
Hitters <- Hitters |> janitor::clean_names()
glimpse(Hitters)

sum(is.na(Hitters$salary))

Hitters <- na.omit(Hitters)
glimpse(Hitters)

out_subset_hitters <- regsubsets(x=salary~., data=Hitters, nvmax=8, method="exhaustive")
summary(out_subset_hitters)

sum_out_subset_hitters <- summary(out_subset_hitters)
sum_out_subset_hitters$cp

sum_out_subset_hitters$which[which.min(sum_out_subset_hitters$cp), ]

coef(out_subset_hitters, which.min(sum_out_subset_hitters$cp))

# ---- Hồi quy từng bước và cross-validtion ----
predict.regsubsets <- function(object, newdata, id_model){
  form <- as.formula(object$call[[2]])
  x_mat <- model.matrix(form, newdata)
  coef_est <- coef(object, id = id_model)
  x_vars <- names(coef_est)
  res <- x_mat[, x_vars] %*% coef_est
  return(as.numeric(res))
}

n_hitter <- nrow(Hitters)
k <- 5

set.seed(21)
folds <- sample(rep(1:k, length = n_hitter))

which(folds == 1)

cv_error_hitters_rj <- matrix(0, nrow = k, ncol = 19)
for(r in 1:k){
  Hitters_train_r <- Hitters[folds != r, ]
  Hitters_test_r <- Hitters[folds == r, ]
  out_subset_hitters_folds <- regsubsets(x = salary ~ ., data = Hitters_train_r,
                                         method = "exhaustive", nvmax = 19)
  for(j in 1:19){
    pred_rj <- predict(out_subset_hitters_folds,
                       newdata = Hitters_test_r, id_model = j)
    cv_error_hitters_rj[r, j] <- sqrt(mean((Hitters_test_r$salary - pred_rj)ˆ2))
  }
}
cv_error_hitters <- colMeans(cv_error_hitters_rj)

ggplot(data = data.frame(x = c(1:19), y = cv_error_hitters),
       mapping = aes(x = x, y = y)) +
  geom_point() +
  geom_line() +
  labs(x = "Number of predictors", y = "RMSE") +
  theme_bw()

which.min(cv_error_hitters)

out_subset_hitters_2 <- regsubsets(x = salary ~ ., data = Hitters,
                                   method = "exhaustive", nvmax = 19)
coef(out_subset_hitters_2, id = which.min(cv_error_hitters))



