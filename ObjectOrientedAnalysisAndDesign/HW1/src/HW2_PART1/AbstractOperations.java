package HW2_PART1;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author Mercan Karacabey
 */
public abstract class AbstractOperations {
     
    protected ArrayList<Double>aListForDouble = new ArrayList<>();
    public String writeFileString="";
    
    //This function read doubles from file . 
    //File format must be this;
    //EX:
    //1.2
    //2.3
    //3.4
    //there must be a symbol->'\n' between them
    public ArrayList<Double> readFileOperation(String filePath) throws FileNotFoundException, IOException
    {
        File file = new File(filePath);
        BufferedReader reader = null;
        reader = new BufferedReader(new FileReader(file));
        String satir = reader.readLine();
            while (satir!=null) {
                //System.out.println(satir);
                aListForDouble.add(Double.parseDouble(satir));
                satir = reader.readLine();
            }
        return aListForDouble;
        
    } 
    
    //ABSTRACT FUNCTION:This function will override by extended class
    public abstract void mainOperation();
    
    //This function save results as string to file(file has taken as parameter)
    public void writeFileOperation(String filePath) throws IOException
    {
        File f=new File(filePath);
        FileWriter fw=new FileWriter(f);   
        fw.write(writeFileString); 
        fw.close(); 
    }
    
}
