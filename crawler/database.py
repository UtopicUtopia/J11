from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy_utils import create_database, database_exists

# database constants
DBIP = 'localhost'  # ip address of crawler database located
DBAC = 'root'  # database account
DBPW = '1234'  # database password
DBNM = 'crawler'  # database name

engine = create_engine('mysql://%s:%s@%s/%s?charset=utf8' % (DBAC, DBPW, DBIP, DBNM))
session = scoped_session(sessionmaker(autocommit=False, autoflush=False, bind=engine))

Base = declarative_base()
Base.query = session.query_property()


def init_db():
    if not database_exists(engine.url):
        create_database(engine.url)
    Base.metadata.create_all(engine)
