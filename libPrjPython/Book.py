from Media import Media

class Book(Media):
    
    def __init__(self, callno, title, subject, author, description, publisher, city, year, series, notes):
        super(Book, self).__init__(callno, title, subject, notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.city = city
        self.year = year
        self.series = series
    
    def display(self):
       print "---------------Book Details-------------------------------------------------------------------------"
       super(Book, self).display()
       print "Author               : ", self.author
       print "Description          : ", self.description
       print "Publisher            : ", self.publisher
       print "City                 : ", self.city
       print "Year                 : ", self.year
       print "Series               : ", self.series
       print "Notes                : ", self.notes
       print "\n"

    def compare_other(self,srch_other):
        return srch_other in self.description or srch_other in self.notes or srch_other in self.year        
