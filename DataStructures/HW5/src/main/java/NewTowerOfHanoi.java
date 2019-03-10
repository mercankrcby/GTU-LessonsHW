/**
 *
 * @author Mercan
 */

/**
 * NewTowerOfHanoi
 * Classin amaci:TowerOfHanoi'yi iterative  olusturmaktir
 *
 */
public class NewTowerOfHanoi {

        private int nDisks; // INSTANCE VARIABLE

    /**
     * Constructor
     *
     */
    public NewTowerOfHanoi(int nDisks)
    { // CONSTRUCTOR
        this.nDisks=nDisks;
    }

    /**
     * Bu fonksiyon sayesinde towerOFHanoi iterative halde yazilmistir
     */
    public void execute(){
        int n=nDisks; // NUMBER OF DISKS
        int diskCounter=0;
        int i=0,d=0;
        int x=0;
        int k=0;
        int counter;
        int returnVal;
        int directionRet;
        int temp;
        //toplam adim sayisi
        int limit = (int)Math.pow(2,n)-1; // NUMBER OF ITERATIONS = 2^n - 1
        for(i=0;i<limit;i++){
            x=i+1;
            for(diskCounter=0;x%2==0;diskCounter++)
            {
                x/=2;
             
            } 
            int disk=diskCounter;
            k=i;
            temp=disk;
            while(temp--!=0)
            {
            k/=2;
            }
            returnVal=(k+1)/2;
            directionRet=2 - (n + disk)%2;
            //source ve destination gelen degerlere bagli olarak return edilmistir
            int source = (returnVal*directionRet)%3;
            int destination = (source+ directionRet)%3;
            move(disk,source,destination);
        }  

    }

    /**
     * Hareketler adim adim basilacaktir
     * @param disk disk sayisi
     * @param source kaynak noktasi
     * @param destination hedef noktasi
     */
    private void move(int disk, int source, int destination) {
        System.out.println("Move Disk " + (disk+1)+ " from Tower " + (source+1) + " to Tower " + (destination+1));
    }
    

}
