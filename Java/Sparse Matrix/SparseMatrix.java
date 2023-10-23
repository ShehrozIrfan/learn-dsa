import java.util.HashMap;
import java.util.Map;

// In this example, the SparseMatrix class uses a Map to store the non-zero elements, 
// and it provides methods for setting and getting values at specific positions in 
// the matrix. The print method is used to display the matrix.

public class SparseMatrix {
    private int numRows;
    private int numCols;
    private Map<Integer, Map<Integer, Integer>> matrix;

    public SparseMatrix(int numRows, int numCols) {
        this.numRows = numRows;
        this.numCols = numCols;
        this.matrix = new HashMap<>();
    }

    public void set(int row, int col, int value) {
        if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
            if (value != 0) {
                if (!matrix.containsKey(row)) {
                    matrix.put(row, new HashMap<>());
                }
                matrix.get(row).put(col, value);
            } else {
                // If the value is zero, remove the entry from the map
                if (matrix.containsKey(row)) {
                    matrix.get(row).remove(col);
                    if (matrix.get(row).isEmpty()) {
                        matrix.remove(row);
                    }
                }
            }
        } else {
            throw new IllegalArgumentException("Invalid row or column index");
        }
    }

    public int get(int row, int col) {
        if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
            if (matrix.containsKey(row) && matrix.get(row).containsKey(col)) {
                return matrix.get(row).get(col);
            }
        }
        return 0; // Default value for zero elements
    }

    public void print() {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                System.out.print(get(i, j) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int numRows = 5;
        int numCols = 5;
        SparseMatrix sparseMatrix = new SparseMatrix(numRows, numCols);

        sparseMatrix.set(0, 0, 1);
        sparseMatrix.set(1, 1, 2);
        sparseMatrix.set(2, 2, 3);
        sparseMatrix.set(3, 3, 4);

        sparseMatrix.print();
    }
}
