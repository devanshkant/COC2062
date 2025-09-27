def QUICK(A, BEG, END):
    LEFT, RIGHT, LOC = BEG, END, BEG
    while True:
        # Scan from right to left
        while A[LOC] <= A[RIGHT] and LOC != RIGHT:
            RIGHT -= 1
        if LOC == RIGHT:
            break
        if A[LOC] > A[RIGHT]:
            A[LOC], A[RIGHT] = A[RIGHT], A[LOC]
            LOC = RIGHT

        # Scan from left to right
        while A[LEFT] <= A[LOC] and LEFT != LOC:
            LEFT += 1
        if LOC == LEFT:
            break
        if A[LEFT] > A[LOC]:
            A[LEFT], A[LOC] = A[LOC], A[LEFT]
            LOC = LEFT
    return LOC


def quickSort(A):
    LOWER, UPPER = [], []
    LOWER.append(0)
    UPPER.append(len(A) - 1)

    while LOWER:
        BEG, END = LOWER.pop(), UPPER.pop()

        if BEG < END:
            LOC = QUICK(A, BEG, END)

            # Push left sublist
            if BEG < LOC - 1:
                LOWER.append(BEG)
                UPPER.append(LOC - 1)

            # Push right sublist
            if LOC + 1 < END:
                LOWER.append(LOC + 1)
                UPPER.append(END)


# Example usage
arr = [34, 7, 23, 32, 5, 62]
quickSort(arr)
print("Sorted array:", arr)
