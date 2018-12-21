main <- function(){
  setwd("~/Documents/RO/data05")
  
  #read data from file	
  df.hc <- read.table("hc_3.dat", header = TRUE, sep = "")
  
  #compute mean for each search space id
  #df.perf <- summaryBy(fitness ~ id, data = df.hc)
  fitness.mean <- c()
  for (i in 0:59){
    fitness.mean <- c(fitness.mean, mean(df.hc[df.hc$id == i,]$fitness))
  }
  #save into data frame
  df.perf <- data.frame(id = 0:59, fitness.mean = fitness.mean)
  hist(df.hc[df.perf$id == 8,]$fitness)
  hist(df.hc[df.perf$id == 41,]$fitness, add = TRUE, col = "red")
  hist(df.hc[df.perf$id == 59,]$fitness, add = TRUE, col = "yellow")
  wilcox.test(df.hc[df.hc$id == 8,]$fitness, df.hc[df.hc$id == 41,]$fitness)
  wilcox.test(df.hc[df.hc$id == 8,]$fitness, df.hc[df.hc$id == 59,]$fitness)
  
  #
  
  df.rnd <- read.table("rnd_3.dat", header = TRUE, sep = "")
  #bind the data frames
  df.all <- cbind(df.perf, df.rnd)
  #matrix of scatter plots
  pairs(df.all)
  #one specific plot between muplus and fitness.mean
  plot(fitness.mean ~ muplus, data = df.all)
  # pairs of correlation coefficients
  cor(df.all)
  #linear model 
  model <- lm (fitness.mean ~ muplus, data = df.all)
  summary(model)
  abline(model)
  
  plot(fitness.mean ~log(f5), data = df.all)
  model <- lm (fitness.mean ~log(f5), data = df.all)
  summary(model)
  abline(model)
  

  }

