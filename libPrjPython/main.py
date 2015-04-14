from SearchEngine import SearchEngine

results = []
searchEngineObj = SearchEngine()

def one():
    srch_str = raw_input("Enter the Call No.: ")
    results = searchEngineObj.search_By_CallNo(srch_str) 
    if len(results) > 0:
        for eachItem in results:
            eachItem.display()
        print "\n"
    else:
        print "No Matching Media Objects Found!!!"

def two():
    srch_str = raw_input("Enter the Title: ")
    results = searchEngineObj.search_By_Title(srch_str) 
    if len(results) > 0:
        for eachItem in results:
            eachItem.display()
        print "\n"
    else:
        print "No Matching Media Objects Found!!!"
    
def three():
    srch_str = raw_input("Enter the Subject: ")
    results = searchEngineObj.search_By_Subject(srch_str) 
    if len(results) > 0:
        for eachItem in results:
            eachItem.display()
        print "\n"
    else:
        print "No Matching Media Objects Found!!!"


def four():
    srch_str = raw_input("Enter a word/phrase: ")
    results = searchEngineObj.search_By_Other(srch_str)
    if len(results) > 0:
        for eachItem in results:
            eachItem.display()
        print "\n"
    else:
        print "No Matching Media Objects Found!!!"

def five():
    exit()

def default():
    print "No such option exists!!!"

takeaction = {
    "1" : one,
    "2" : two,
    "3" : three,
    "4" : four,
    "5" : five}

while True:
    
    print "----------------Library Search----------"
    print "Choose from the below options"
    print "1. Search By Call No."
    print "2. Search By Title"
    print "3. Search By Subject"
    print "4. Search By Other"
    print "5. Exit"

    option = raw_input("Choose option: ")
    takeaction.get(option,default) ()
    
