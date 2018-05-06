class Solution:
    # @param A : list of integers
    # @return an integer
    def countInversions(self, A):
        A, inversions = self.mergeSort(A)
        return inversions
    
    def merge(self, A, B):
        i,j,k,inversions = 0, 0, 0, 0
        len_a = len(A)
        len_b = len(B)
        C = [0]*(len_a + len_b)
        for k in xrange(len(A+B)):
            if A[i]<=B[j]:
                C[k] = A[i]
                i +=1
            else:
                C[k] = B[j]
                j+=1
                inversions += len_a-i
        
        return C, inversions
            
    
    def mergeSort(self, A):
        if len(A)==1:
            return A[0]
        
        leftSorted, inv_left = self.mergeSort(A[:len(A)/2])
        rightSorted, inv_right = self.mergeSort(A[len(A)/2:])
        
        A, merge_invs = self.merge(leftSorted, rightSorted)
        return A, inv_left + inv_right + merge_invs

