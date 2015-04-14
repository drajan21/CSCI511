from Media import Media

class Film(Media):
    
    def __init__(self, callno, title, subject, director, notes, year):
        super(Film, self).__init__(callno, title, subject, notes)
        self.director = director
        self.year = year
    
    def display(self):
       print "---------------Film Details-------------------------------------------------------------------------"
       super(Film, self).display()
       print "Director             : ", self.director
       print "Notes                : ", self.notes
       print "Year                 : ", self.year
       print "\n"

    def compare_other(self,srch_other):
        return srch_other in self.director or srch_other in self.notes or srch_other in self.year
