t = int(input())
for a in range(t):
    rating = int(input())
    if rating >= 1900:
        print('Division 1')
    if rating >= 1600 and rating <= 1899:
        print('Division 2')
    if rating >= 1400 and rating <= 1599:
        print('Division 3')
    if rating <= 1399:
        print('Division 4')
