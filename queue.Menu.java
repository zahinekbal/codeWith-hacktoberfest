import java.util.Scanner;
class ArrayQueue{
    private int[]que;
    private int size,f, r, count=0;
    public ArrayQueue(int n){
        size = n ;
        f=-1;
        r=-1;
        que = new int[size];
    }
    public void enque(int num){
        if(r == size-1)
            System.out.println("overflow");
        else if (r == -1 && f==-1){
            r=0;
            f=0;
            que[r]=num;}
        else {
            r=r+1;
            que[r]=num;
        }
    }
    public void deque()       {
        if (r == -1 && f==-1){
            System.out.println("underflow");
        }
        else  if(f==r){
            int temp=que[f];
            System.out.println("Item Dequed ="+temp);
            f=-1;
            r=-1;
        }
        else{ int temp=que[f];
            System.out.println("Item Dequed ="+temp);
            f=f+1;
        }
    }
    public int peek(){
        return que[f];   }
    public boolean overflow(){
        return r == size-1;   }

    public boolean underflow()       {
        return (f==-1 && r == -1); }

    public void display()       {
        if (r == -1 && f==-1){
            System.out.println("underflow");
        }
        else{ System.out.print("Queue is= ");
            for(int i=f;i<=r;i++){
                System.out.print(que[i]+" ");
            }
        }
    }
    public int totalq()       {
        if (r == -1 && f==-1){
            System.out.println("underflow");
            return 0; }
        else{
            for(int i=f;i<=r;i++){
                count++;}
            return count;
        }
    }
}
public class queueMenu {
    public static void main(String[] args) {
        char ch;
        Scanner sc = new Scanner(System.in);
        System.out.println("Queue Implementation with Array");
        System.out.println("Enter Size of Queue=");
        int n = sc.nextInt();
        ArrayQueue QA = new ArrayQueue(n);
        do{
            System.out.println("Queue Operations");
            System.out.println("1.Enque \n"+"2.Deque \n"+"3.Peek \n"+ "4.Display \n"+"5.Overflow Check \n"+"6.Underflow Check\n" +"7. Total elements in queue\n");
            int choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.println("Enque operation input a number");
                    int val= sc.nextInt();
                    QA.enque(val);
                    break;
                case 2:
                    System.out.println("Deque operation");
                    QA.deque();
                    break;
                case 3:
                    System.out.println("Peek Operation " + QA.peek());
                    break;
                case 4:
                    System.out.println("display operation");
                    QA.display();
                    break;
                case 5:
                    System.out.println("Overflow status = "+ QA.overflow());
                    break;
                case 6:
                    System.out.println("Empty status = "+ QA.underflow());
                    break;
                case 7:
                    System.out.println("Total Elements in queue are "+ QA.totalq());
                    break;
                default:
                    System.out.println("invalid input");
            }
            QA.display();
            System.out.println("\n Do you want to continue(y/n)");
            ch= sc.next().charAt(0);
        }
        while(ch == 'y' || ch == 'Y');
    }
}
