package hw2_mercan_karacabey_131044034;

import HW2_PART1.AbstractOperations;
import HW2_PART1.DCT;
import HW2_PART1.DFT;
import HW2_PART2.SynchronizedIngredients;
import java.io.IOException;

/**
 *
 * @author Mercan Karacabey
 */
public class HW2_MERCAN_KARACABEY_131044034 {


    public static void main(String[] args) throws IOException {
        
        //Testing for PART1
        
        AbstractOperations op1 = new DFT();
        op1.readFileOperation("input.txt");
        op1.mainOperation();
        op1.writeFileOperation("output.txt"); 
        
        AbstractOperations op2 = new DCT();
        op2.readFileOperation("input.txt");
        op2.mainOperation();
        op2.writeFileOperation("output.txt");
        
        
        //Testing for PART2
        
        final SynchronizedIngredients syncIngredients = new SynchronizedIngredients();
        
        //Firstly , I created 4 threads for METIN,ALI,FEYYAZ and KEZBAN operations. And I started them .
        
        Thread ali = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    syncIngredients.doJob(0);
                }
            }
        });
        ali.start();

        Thread metin = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    syncIngredients.doJob(1);
                }
            }
        });
        metin.start();

        Thread feyyaz = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    syncIngredients.doJob(2);
                }
            }
        });
        feyyaz.start();

        Thread kezban = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    try {
                        syncIngredients.doKezban();
                        Thread.sleep(5000);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        });
        kezban.start();

    }   
}
