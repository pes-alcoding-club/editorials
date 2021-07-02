We will process boards one at a time. For each board j, count the number of previous board that forms a suitable pair.

If the jth board is square, boards with at least one dimension equal to w_j are suitable.

Otherwise, boards with at least one dimension equal to the height and boards with at least one dimension equal to width are suitable. But if we add boards of the first and second types separately, then boards that have both dimension w_j and dimension h_j will be counted twice - the number of such monitors must be subtracted.

Depending on the data structure used, the complexity of the solution will be O(n) or O(n log n).
