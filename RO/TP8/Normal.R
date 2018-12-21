binorm <- function(n){
  x1 <- rnorm(n = n, mean = 0, sd = 1)
  x2 <- rnorm(n = n, mean = 0, sd = 1)
  return(list(x1 = x1, x2 = x2))
}
binorm2 <- function(n,sigma){
  x1 <- rnorm(n = n, mean = 0, sd = sigma)
  x2 <- rnorm(n = n, mean = 0, sd = sigma)
  return(list(x1 = x1, x2 = x2))
}
binorm3 <- function(n,sigma1, sigma2){
  x1 <- rnorm(n = n, mean = 0, sd = sigma1)
  x2 <- rnorm(n = n, mean = 0, sd = sigma2)
  return(list(x1 = x1, x2 = x2))
}
binorm4 <- function(n,sigma1, sigma2, theta){
  x1 <- rnorm(n = n, mean = 0, sd = sigma1)
  x2 <- rnorm(n = n, mean = 0, sd = sigma2)
  return(list(x1 = cos(theta) * x1+ sin(theta) * x2,
              x2 = -sin(theta) * x1 + cos(theta) * x2)) #pas sur
}
mainBi <- function(){
  n <- 1000
  
  res <- binorm(n)
  plot(res$x1, res$x2, xlim=c(-25,25), ylim = c(-25,25))
  res <- binorm2(300, sigma=5)
  points(res$x1, res$x2, col ="blue")
  res <- binorm3(300, sigma1=1, sigma2=5)
  points(res$x1, res$x2, col ="yellow")
  
}

main <- function(){
  x <- seq(-10,10, by = 0.01)
  plot(x, dnorm(x, mean = 0, sd = 1),ylim = c(0,0.9),type ="l")
  lines(x,dnorm(x,mean = 3, sd = 1), col="red")
  lines(x,dnorm(x,mean = -4, sd = 1), col="blue")
  lines(x,dnorm(x,mean = 0, sd = 0.5), col="purple")
  lines(x,dnorm(x,mean = 0, sd = 2), col="green")
}
#main()
mainBi()
