source("system.r")
#checkDependencies()

parse_MK <- function()
{
    xpath <- "//a"
    
        list_parsed  <- htmlTreeParse(MK, useInternalNodes=TRUE, trim=TRUE)
        links <- xpathSApply(list_parsed, xpath, xmlGetAttr, "href") # article contains photo          
        for(link in links)
        {
            
            if(grepl("^http://news.mk.co.kr/newsRead.php", link))
            {
                article_parsed <- htmlTreeParse(link, useInternalNodes=TRUE, trim=TRUE)
                article <- xpathSApply(article_parsed, "//*[@class='left_content']/*[@id='article_body']/div", xmlValue)
                print(article)
            }

        }
}
