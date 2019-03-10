package HW2_PART1;

import hw2_mercan_karacabey_131044034.Complex;
import java.util.ArrayList;

/**
 *
 * @author Mercan Karacabey
 */
public class DFT extends AbstractOperations{
    
    Complex complexNumber = new Complex();
    ArrayList<Complex> complexInputList = new ArrayList<Complex>();
    ArrayList<Complex> complexResultList = new ArrayList<Complex>();
    //This function operates DFT with complex number. All operations do with complex number.
    //And It produce list which formed with complex numbers.
    public void mainOperation(){
        doubleToComplexNumber();
        for (int k = 0; k < complexInputList.size(); k++) {  // For each output element
            double sumreal = 0;
            double sumimag = 0;
            for (int t = 0; t < complexInputList.size(); t++) {  // For each input element
                double angle = 2 * Math.PI * t * k / complexInputList.size();
                sumreal +=  complexInputList.get(t).realPart * Math.cos(angle) + complexInputList.get(t).imaginaryPart * Math.sin(angle);
                sumimag += -complexInputList.get(t).realPart * Math.sin(angle) + complexInputList.get(t).imaginaryPart * Math.cos(angle);
            }
            Complex resultNumber = new Complex(sumreal,sumimag);
            complexResultList.add(resultNumber);  
            //System.out.println("outReal["+k+"]="+complexResultList.get(k).realPart);
            //System.out.println("outImag["+k+"]="+complexResultList.get(k).imaginaryPart);
        }
        convertToStringFromComplexList();
    }
    //Firstly , this function convert to complex number from double for using mainOperation function
    public void doubleToComplexNumber()
    {
        ArrayList<Complex> complexList=new ArrayList<Complex>();
        for(int i=0;i<aListForDouble.size();++i)
        {
            Complex complexNumber = new Complex(aListForDouble.get(i),0);
            complexList.add(complexNumber);
        }
        complexInputList = complexList;
    }
    //This function use for saving to file.
    public void convertToStringFromComplexList()
    {
        for(int i=0;i<complexResultList.size();++i){
            writeFileString +=complexResultList.get(i).realPart + " "+complexResultList.get(i).imaginaryPart+"i"+"\n";
        }
    }
}
