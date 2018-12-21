

f <- function(x) {
  return( (x[1]-3)^2 + (x[2]-1)^2)
}
gradientf <- function(x){
  y <- c(2*(x[1] - 3), 2*(x[2] - 1))
  return(y)
}
descenteGradientPasFixe <- function(f, gradientf,x0 , sigma, nbiter){
  x <- x0
  
  v <- c(f(x))
  for(i in 1:nbiter){
   w <- -(gradientf(x))
   x <- x + sigma*w
   
   v <- c(v, f(x))
  }
  return( list(x=x, dyn=v))
}

Newton <- function(f,df,x0,precision){
  x <- x0
  while(abs(f(x)) > precision){
    x <- x - (f(x) / df(x))
  }
  return(x)
}
f1 <- function(x) {
  return(-x^3 + x^2 - 2*x + 5)
}
df1 <- function(x) {
  return(-3*x^2+2*x-2)
}

f2 <- function(x){
  return(10*x^4 -20*x^3 -90*x^2+20*x +80)
}
df2 <- function(x) {
  return(40*x^3 - 60*x^2 - 180*x + 20)
}
ddf2 <- function(x) {
  return(120*x^2 - 120*x - 180)
}
mainNewton <- function(){
  x0 <- 0
  x <- Newton(f1,df1,x0,0.01)
  cat(x,f1(x), "\n")
  
  x <- Newton(df2,ddf2,x0,0.0001)
  cat(x,df2(x),f2(x), "\n")
  
  xx <- seq(0, 1, by=0.01)
  plot(xx, f2(xx))
}


main <- function(){
  x<- c(1,3)
  cat(f(x), "\n")
  cat(gradientf(x), "\n")
  res <- descenteGradientPasFixe(f,gradientf,c(1,3), 0.01, 1000)
  plot(res$dyn, type = "l")
  res <- descenteGradientPasFixe(f,gradientf,c(1,3), 0.001, 1000)
  plot(res$dyn, col = "red")
  res <- descenteGradientPasFixe(f,gradientf,c(1,3), 0.1, 1000)
  plot(res$dyn, col = "blue")
  res <- descenteGradientPasFixe(f,gradientf,c(1,3), 1, 1000)
  plot(res$dyn, col = "yellow")
}

  
