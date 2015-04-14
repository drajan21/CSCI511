class Media(object):
    
    def __init__(self, callno, title, subject, notes):
        self.callno = callno
        self.title = title
        self.subject = subject
        self.notes = notes

    def compare_callno(self, srch_callno):
        return srch_callno in self.callno
    
    def compare_title(self, srch_title):
        return srch_title in self.title

    def compare_subject(self, srch_subject):
        return srch_subject in self.subject

    def display(self):
        print "Call No.             : ", self.callno
        print "Title                : ", self.title
        print "Subject              : ", self.subject
       
