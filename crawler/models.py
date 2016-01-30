import os
import sys
import datetime
from sqlalchemy import Column, ForeignKey, Integer, String, Date
from database import Base
from sqlalchemy.orm import relationship


# AUTO_INCREMENT is automatically assigned to first integer primary key of table.
# INDEX is anonymously created (using an auto-generated name ix_<column lable>) for
# a single column using the inline 'index' keyword on column


class Url(Base):
    __tablename__ = 'url'
    # definition of columns for table url
    id = Column(Integer, primary_key=True)
    url = Column(String(255), unique=True, index=True, nullable=False)
    updated = Column(Date, default=datetime.datetime.now())

    def __init__(self, url):
        self.url = url


class Word(Base):
    __tablename__ = 'word'
    # definition of columns for table word
    id = Column(Integer, primary_key=True)
    word = Column(String(255), index=True, nullable=False)

    def __init__(self, word):
        self.word = word


class Wordlocation(Base):
    __tablename__ = 'wordlocation'
    # definition of columns for table wordlocation
    id = Column(Integer, primary_key=True)
    urlid = Column(Integer, ForeignKey("url.id", onupdate="CASCADE", ondelete="CASCADE"), nullable=False)
    wordid = Column(Integer, ForeignKey("word.id", onupdate="CASCADE", ondelete="CASCADE"), index=True, nullable=False) 
    url = relationship(Url, foreign_keys=[urlid])
    word = relationship(Word, foreign_keys=[wordid])
    

class Link(Base):
    __tablename__ = 'link'
    id = Column(Integer, primary_key=True)
    urlfromid = Column(Integer, ForeignKey("url.id", onupdate="CASCADE", ondelete="CASCADE"), index=True, nullable=False)
    urltoid = Column(Integer, ForeignKey("url.id", onupdate="CASCADE", ondelete="CASCADE"), index=True, nullable=False)
    urlto = relationship(Url, foreign_keys=[urltoid])
    urlfrom = relationship(Url, foreign_keys=[urlfromid])
