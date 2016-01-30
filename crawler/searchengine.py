import urllib2
from BeautifulSoup import *
from urlparse import urljoin
import MySQLdb as db
from database import session, init_db
from models import Url, Word, Wordlocation, Link 

# ignore word set
IGNORES = set(['the', 'of', 'to', 'and', 'a'])


class crawler:

    def __init__(self):
        init_db()
        self.con = db.connect("127.0.0.1", "root", "1234", "crawler", charset="utf8")
        self.cur = self.con.cursor()
        pass

    def __del__(self):
        self.con.close()
        pass

    def dbCommit(self):
        self.con.commit()
        pass

    def getEntryId(self, table, field, value, createNew=True):
        eid = self.con.execute("SELECT id FROM %s WHERE %s='%s'" % (table, field, value)).fetchone()        
        if not eid:
            cur = self.con.execute("INSERT INTO %s(%s) VALUES(%s)" % (table, field, value))
            return cur.lastrowid
        else:
            return eid[0]

    def addToIndex(self, url, soup):
        print 'Indexing %s' % url

    def getTextOnly(self, soup):
        ptext = soup.string
        if not ptext:
            contents = soup.contents

            rtext = ""
            for t in contents:
                subtext = self.getTextOnly(t)
                rtext += subtext + '\n'
            return rtext
        else:
            return ptext.strip()

    def separateWords(self, text):
        splitter = re.compile('\\W*')
        return [s.lower() for s in splitter.split(text) if s != '']

    def isIndexed(self, url):
        query = session.query(Url).filter(Url.url.like(url))
        result = query.first()
        if result:
            v = self.cur.execute("SELECT * FROM wordlocation WHERE urlid = '%d'" % result.id).fetchone()
            if v:
                return True

        return False


    def addLinkRef(self, urlFrom, urlTo, linkText):
        pass


    def crawl(self, pages, depth = 2):
        for d in range(depth):
            newPages = set()
            for page in pages:
                try:
                    c = urllib2.urlopen(page)
                except:
                    print "Could not open %s" % page
                    continue

                soup = BeautifulSoup(c.read())
                self.addToIndex(page, soup)
                links = soup('a')
                for link in links:
                    if('href' in dict(link.attrs)):
                        url = urljoin(page, link['href'])

                        if url.find("'") != -1:
                            continue

                        url = url.split('#')[0]

                        if url[0:4] == 'http' and not self.isIndexed(url):
                            newPages.add(url)

                        linkText = self.getTextOnly(link)
                        self.addLinkRef(page, url, linkText)

                self.dbCommit()
            pages = newPages

    def createIndexTables(self):
        pass


