f <- function(x){
  return (x[1]^2 + x[2]^2)
}
OnePlusOneESfifth <- function (f,sigma, x0,n){
  m <- x0
  fm <- f(m)
  
  v <- c()
  for(i in 1:n){
        xprime <- m + sigma* rnorm(n=2, mean = 0, sd = 1)
        fxprime <- f(xprime)
    if (fm > fxprime){
      m <- xprime
      fm <- f(xprime)
      
      sigma <- sigma * exp(1/3)
    } else {
      sigma <- sigma / (exp(1/3)^(1/4))
    }
       v <- c(v,fm)
  }
  return (list(x=m, dyn =v))
}
OnePlusOneES <- function (f,sigma, x0,n){
  m <- x0
  fm <- f(m)
  
  v <- c()
  for(i in 1:n){
    xprime <- m + sigma* rnorm(n=2, mean = 0, sd = 1)
    fxprime <- f(xprime)
    if (fm > fxprime){
      m <- xprime
      fm <- f(xprime)
      
    }
    v <- c(v,fm)
  }
  return (list(x=m, dyn =v))
}

muSlashMuCommaLambdaES <- function (f, x0,sigma,n, mu, lambda){
  m <- x0
  fm <- f(m)
  trace <- c(fm)
  
  offspring <- matrix(rep(0,2 * lambda), nrow = lambda)
  w <- log(mu + 0.5) - log(1:mu)
  w <- w/ sum(w)
  for(i in 1:n){
    foffspring <- c()
      for(j in 1:lambda){
        offspring[j,] <-  m + sigma*rnorm(n = 2,mean = 0, sd=1)
        foffspring <- c(foffspring, f(offspring[j,]))
      }
    
    ordered <- order(foffspring)
    m <- c(0,0)
    
      for(j in 1:mu){
       m <- m + w[j] * offspring[ordered[j],]
      }
    trace <- c(trace, f(m))
  }
  return (list(x=m, dyn =trace))
}



mainES <- function(){
  x0 <- c(3,1)
  #res <- OnePlusOneES(f,x0,1000,sigma = 0.1)
  #cat(f(res$x), res$x, "\n")
  #plot(log(res$dyn), type ="l")
  
  #res <- OnePlusOneESfifth(f,x0,10000,sigma = 1)
  #cat(f(res$x), res$x, "\n")
  #plot(log(res$dyn), type ="l")
  
  res <- muSlashMuCommaLambdaES(f, x0, 100, sigma = 0.1, mu = 10,lambda = 100)
  cat(f(res$x), res$x, "\n")
  plot(log(res$dyn), type ="l")
  
}
mainES()