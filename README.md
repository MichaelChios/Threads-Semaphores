# Threads-Semaphores

Συγχρονισμός εκτέλεσης νημάτων


Να γραφεί πρόγραμμα σε γλώσσα C, που θα συγχρονίζει την
εκτέλεση των παρακάνω νημάτων με χρήση σημαφόρων,
ώστε το νήμα 1 να εμφανίζει τη σωστή τιμή της μεταβλητής x.

δηλ. έχουμε 3 νήματα t1, t2, t3 με κάποιες κοινές μεταβλητές
(a2, b1, c1, c2, x, y, z) που κάνουν τα εξής:

t1: a1 = 10 
a2 = 11 
y = a1 + c1 
print(x)
 
t2: b1 = 20 
b2 = 21 
w = b2 + c2 
x = z - y + w

t3: c1 = 30 
c2 = 31 
z = a2 + b1

Απαραίτητη χρήση linux
