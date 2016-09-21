MK <- "http://news.mk.co.kr/newsList.php?sc=30000016"
YEAR <- 2016

dependencies <- c(
    "XML",
    "stringr",
    "RMySQL"
)

is.installed <- function(mypkg) is.element(mypkg, installed.packages()[,1])

checkDependencies <- function(){
    for(dependency in dependencies)
    {
        if(!is.installed(dependency))
        {
            install.packages(dependency, repos="http://cran.rstudio.com/")
        }

        library(dependency, character.only=TRUE)
        print(paste("[SYSTEM] Import ", dependency, "package"))
    }
}

