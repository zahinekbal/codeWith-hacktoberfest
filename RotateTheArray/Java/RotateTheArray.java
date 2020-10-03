public class RotateTheArray {

	private char[] array;
	private int rotateBy;

	public RotateTheArray() {
		setArray();
		rotateBy = 0;

	}

	public static void main(String[] args) {
		
		RotateTheArray r = new RotateTheArray();
		r.printTheArray();
		r.rotateBy = 4;
		r.rotateArray();
		r.printTheArray();
		r.rotateBy = 6;
		r.rotateArray();
		r.printTheArray();
	}

	private void rotateArray() {
		
		int k;
		char val;
		
		for(int i=0; i<rotateBy; i++) {
			val = array[0];
			for(k=0; k<array.length-1; k++) {
				array[k] = array[k+1];
			}
			array[k] = val;
		}
	}

	private void printTheArray() {
		
		for(int i=0; i<array.length; i++) {
			System.out.print(array[i]+" ");
		}
		System.out.println();
		
	}

	private void setArray() {
		
		char[] a = {'a','b','c','d','e','f','g','h','i','j'};
		array = a;
		
	}



}