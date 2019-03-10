package HW2_PART1;

import java.util.ArrayList;

/**
 *
 * @author Mercan Karacabey
 */
public class DCT extends AbstractOperations{ 
    
    public ArrayList<Double> resultList = new ArrayList<Double>();
    
    //This function operates DCT .
    public void mainOperation(){
        double factor = Math.PI / aListForDouble.size();
        for (int i = 0; i < aListForDouble.size(); i++) {
            double sum = 0;
            for (int j = 0; j < aListForDouble.size(); j++)
		sum += aListForDouble.get(j) * Math.cos((j + 0.5) * i * factor);
		resultList.add(sum) ;//= sum;
        }
        convertToStringFromDoubleList();
    }
    
    //This function helps to convert double list -> string for saving to file
    public void convertToStringFromDoubleList()
    {
        for(int i=0;i<resultList.size();++i)
        {
            writeFileString+=resultList.get(i)+"\n";
        }
    }
}
