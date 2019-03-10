package HW2_PART2;

/**
 *
 * @author Mercan Karacabey
 * This class uses by SynchronizedIngredients
 * 
 * They(input,output and objects )are not created seperately. 
 * They are represented by numerical inputs instead of input,output and objects.
 */
public class Ingredients {
    
    public int input;
    public int output;
    public int obj;

    public int getInput() {
        return input;
    }

    public void setInput(int input) {
        this.input = input;
    }

    public int getOutput() {
        return output;
    }

    public void setOutput(int output) {
        this.output = output;
    }

    public int getObj() {
        return obj;
    }

    public void setObj(int obj) {
        this.obj = obj;
    }

    @Override
    public String toString() {
        return "Ingredients{" + "input=" + input + ", output=" + output + ", obj=" + obj + '}';
    }     
}
