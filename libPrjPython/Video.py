from Media import Media

class Video(Media):
    
    def __init__(self, callno, title, subject, description, distributor, notes, series, label):
        super(Video, self).__init__(callno, title, subject, notes)
        self.description = description
        self.distributor = distributor
        self.series = series
        self.label = label
    
    def display(self):
       print "---------------Video Details-------------------------------------------------------------------------"
       super(Video, self).display()
       print "Description          : ", self.description
       print "Distributor          : ", self.distributor
       print "Notes                : ", self.notes
       print "Series               : ", self.series
       print "Label                : ", self.label
       print "\n"

    def compare_other(self,srch_other):
        return srch_other in self.description or srch_other in self.notes or srch_other in self.distributor 
