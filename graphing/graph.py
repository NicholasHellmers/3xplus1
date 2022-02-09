import csv
import matplotlib.pyplot as plt
n =[]
loops = []
with open('data/largestLoops.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        n.append(row['n'])
        loops.append(row['loops'])

plt.plot(n,loops)
plt.xlabel('n')
plt.ylabel('loops')
plt.show()