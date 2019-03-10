package HW2_PART2;

import HW2_PART2.Ingredients;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 *
 * @author Mercan Karacabey
 */
public class SynchronizedIngredients extends Object {

    private List<Ingredients> inputs = Collections.synchronizedList(new LinkedList<>());

    public SynchronizedIngredients() {
    }
    //It includes METIN ,ALI and FEYYAZ operations .
    //METIN,ALI and FEYYAZ operates depending on incoming values.
    public void doJob(int type) {
        synchronized (inputs) {
            try {
                //If the list is empty , METIN ,ALI and FEYYAZ will wait.
                while (inputs.isEmpty()) {
                    if(type==0)
                    {
                        System.out.println("Ali is waiting for a transformer and an output file");
                    }
                    if (type==1){
                        System.out.println("Metin is waiting for an input file and output file");
                    }
                    if(type==2)
                    {
                        System.out.println("Feyyaz is waiting for an input file and an output file");
                    }
                    inputs.wait();
                }
                Ingredients ref = (Ingredients) inputs.get(0);
                //Only input file and output file 
                if (type == 0) {
                    if (ref.input != 0 && ref.output != 0) {
                        inputs.clear();
                        ref.obj = 2;
                        System.err.println("ALI");
                        System.out.println("Ali grabbed an input file and a output");
                        System.out.println("Ali is calculating the outputs");
                        System.out.println("Ali has delivered the outputs");
                    }
                } 
                //Only object and output file
                else if (type == 1) {
                    if (ref.obj != 0 && ref.output != 0) {
                        inputs.clear();
                        ref.obj = 3;
                        System.err.println("METIN");
                        System.out.println("Metin grapped output file and a transformer");
                        System.out.println("Metin is calculating the outputs");
                        System.out.println("Metin has delivered the outputs");
                    }
                }
                //Only input file and object
                else if (type == 2) {
                    if (ref.input != 0 && ref.obj != 0) {
                        // create a random output file
                        inputs.clear();
                        ref.obj = 4;
                        System.err.println("FEYYAZ");
                        System.out.println("Feyyaz grapped input file and a transformer");
                        System.out.println("Feyyaz is calculating the outputs");
                        System.out.println("Feyyaz has delivered the outputs");
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    //Kezban generates random numbers and according to this numbers change object members which related.
    public void doKezban() {
        synchronized (inputs) {
            try {
                if (inputs.isEmpty()) {
                    System.out.println("Kezban is waiting for the outputs to be calculated");
                    int rand = new Random().nextInt(3);
                    Ingredients ing = new Ingredients();
                    switch (rand) {
                        case 0:
                            ing.input = 1;
                            ing.obj = 0;
                            ing.output = 1;
                            System.out.println("Kezban brought an input file and an output file");
                            break;
                        case 1:
                            ing.input = 0;
                            ing.obj = 1;
                            ing.output = 1;
                            System.out.println("Kezban brought an object and output file");
                            break;
                        case 2:
                            ing.input = 1;
                            ing.obj = 1;
                            ing.output = 0;
                            System.out.println("Kezban brough an input file and an object");
                            break;
                    }
                    inputs.add(ing);
                    inputs.notifyAll();
                    System.out.println("Kezban has taken the outputs and left");
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }

}

