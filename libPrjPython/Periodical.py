from Media import Media

class Periodical(Media):
    
    def __init__(self, callno, title, subject, author, description, publisher, publishing_history, series, notes, related_titles,
                 other_forms_of_title, govt_doc_no):
        super(Periodical, self).__init__(callno, title, subject, notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.publishing_history = publishing_history
        self.series = series
        self.related_titles = related_titles
        self.other_forms_of_title = other_forms_of_title
        self.govt_doc_no = govt_doc_no
    
    def display(self):
       print "---------------Periodical Details-------------------------------------------------------------------------"
       super(Periodical, self).display()
       print "Author               : ", self.author
       print "Description          : ", self.description
       print "Publisher            : ", self.publisher
       print "Publishing History   : ", self.publishing_history
       print "Series               : ", self.series
       print "Notes                : ", self.notes
       print "Related Titles       : ", self.related_titles
       print "Other Forms of Title : ", self.other_forms_of_title
       print "Govt. Doc No.        : ", self.govt_doc_no
       print "\n"

    def compare_other(self,srch_other):
        return srch_other in self.description or srch_other in self.notes or srch_other in self.series                                        or srch_other in self.related_titles 
