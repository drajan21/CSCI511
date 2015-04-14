from Book import Book
from Periodical import Periodical
from Video import Video
from Film import Film

class SearchEngine(object):

    cardCatalog = []

    def __init__(self):
        book = open("book.txt", "r")
        for eachLine in book:
            bookData = eachLine.strip().split("|")
            self.cardCatalog.append(Book(bookData[0],bookData[1],bookData[2],bookData[3],bookData[4],bookData[5],bookData[6],
                                         bookData[7],bookData[8],bookData[9]))
        book.close()

        periodical = open("periodic.txt", "r")
        for eachLine in periodical:
            periodicalData = eachLine.strip().split("|")
            self.cardCatalog.append(Periodical(periodicalData[0],periodicalData[1],periodicalData[2],periodicalData[3],                                                          periodicalData[4],periodicalData[5],periodicalData[6],periodicalData[7],
                                               periodicalData[8],periodicalData[9],periodicalData[10],periodicalData[11]))
        periodical.close()

        video = open("video.txt", "r")
        for eachLine in video:
            videoData = eachLine.strip().split("|")
            self.cardCatalog.append(Video(videoData[0],videoData[1],videoData[2],videoData[3],videoData[4],videoData[5],
                                          videoData[6],videoData[7]))
        video.close()

        film = open("film.txt", "r")
        for eachLine in film:
            filmData = eachLine.strip().split("|")
            self.cardCatalog.append(Film(filmData[0],filmData[1],filmData[2],filmData[3],filmData[4],filmData[5]))
        film.close()

    
    def search_By_CallNo(self, search_str):
        result = []
        for eachItem in self.cardCatalog:
            if eachItem.compare_callno(search_str) == True:
                result.append(eachItem)
        return result

    def search_By_Title(self, search_str):
        result = []
        for eachItem in self.cardCatalog:
            if eachItem.compare_title(search_str) == True:
                result.append(eachItem)
        return result

    def search_By_Subject(self, search_str):
        result = []
        for eachItem in self.cardCatalog:
            if eachItem.compare_subject(search_str) == True:
                result.append(eachItem)
        return result

    def search_By_Other(self, search_str):
        result = []
        for eachItem in self.cardCatalog:
            if eachItem.compare_other(search_str) == True:
                result.append(eachItem)
        return result
