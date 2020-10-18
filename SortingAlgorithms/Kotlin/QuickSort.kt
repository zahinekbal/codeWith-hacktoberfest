class QuickSort {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val array = arrayOf(90, 56, 101, 45, 65, 99, 67, 89, 34, 23)
            println("Before Sorted")
            for (element in array) {
                print("$element ")
            }
            println()
            quickSort(array, 0, 9)
            println("Sorted Array")
            for (element in array) {
                print("$element ")
            }
        }

        private fun partition(a: Array<Int>, beg: Int, end: Int): Int {    //int a[], int beg, int end
            var left: Int = 0
            var right: Int
            var temp: Int
            var loc: Int
            var flag: Int
            loc = beg.also({ left = it })
            right = end
            flag = 0
            while (flag != 1) {
                while (a.get(loc) <= a.get(right) && loc != right) right--
                if (loc == right) flag = 1 else if (a.get(loc) > a.get(right)) {
                    temp = a.get(loc)
                    a[loc] = a.get(right)
                    a[right] = temp
                    loc = right
                }
                if (flag != 1) {
                    while (a.get(loc) >= a[left] && loc != left) left++
                    if (loc == left) flag = 1 else if (a.get(loc) < a.get(left)) {
                        temp = a.get(loc)
                        a[loc] = a.get(left)
                        a[left] = temp
                        loc = left
                    }
                }
            }
            return loc
        }

        private fun quickSort(a: Array<Int>, beg: Int, end: Int) {
            var loc: Int
            if (beg < end) {
                loc = partition(a, beg, end)
                quickSort(a, beg, loc - 1)
                quickSort(a, loc + 1, end)
            }
        }
    }
}
