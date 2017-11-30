package hw2_mercan_karacabey_131044034;

/**
 *
 * @author Mercan Karacabey
 */
public class Complex {
    public double realPart;
    public double imaginaryPart;
    public Complex()
    {
        realPart= 0.0;
        imaginaryPart=0.0;
    }
    public Complex(double rPart,double iPart)
    {
        this.realPart=rPart;
        this.imaginaryPart=iPart;
    }
    public double getRealPart() {
        return realPart;
    }

    public void setRealPart(double realPart) {
        this.realPart = realPart;
    }

    public double getImaginaryPart() {
        return imaginaryPart;
    }

    public void setImaginaryPart(double imaginaryPart) {
        this.imaginaryPart = imaginaryPart;
    } 
    public Complex plus(Complex a,Complex b) {
        double real = a.realPart + b.realPart;
        double imag = a.imaginaryPart + b.imaginaryPart;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is (this - b)
    public Complex minus(Complex a,Complex b) {
        double real = a.realPart - b.realPart;
        double imag = a.imaginaryPart - b.imaginaryPart;
        return new Complex(real, imag);
    }
    public Complex times(Complex a,Complex b) {
        //Complex a = this;
        double real = a.realPart * b.realPart - a.imaginaryPart * b.imaginaryPart;
        double imag = a.realPart * b.imaginaryPart + a.imaginaryPart * b.realPart;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is the conjugate of this
    public Complex conjugate(Complex number) {
        return new Complex(number.realPart, -number.imaginaryPart);
    }

    // return a new Complex object whose value is the reciprocal of this
    public Complex reciprocal(Complex number) {
        double scale = number.realPart*number.realPart + number.imaginaryPart*number.imaginaryPart;
        return new Complex(number.realPart / scale, -number.imaginaryPart / scale);
    }
    // return a / b
    public Complex divides(Complex a,Complex b) {
        //Complex a = this;
        Complex temp=reciprocal(b);
        return times(a,temp);
    }

    // return a new Complex object whose value is the complex exponential of this
    public Complex exp(Complex number) {
        return new Complex(Math.exp(number.realPart) * Math.cos(number.imaginaryPart), Math.exp(number.realPart) * Math.sin(number.imaginaryPart));
    }

    // return a new Complex object whose value is the complex sine of this
    public Complex sin(Complex a) {
        return new Complex(Math.sin(a.realPart) * Math.cosh(a.imaginaryPart), Math.cos(a.realPart) * Math.sinh(a.imaginaryPart));
    }

    // return a new Complex object whose value is the complex cosine of this
    public Complex cos(Complex number) {
        return new Complex(Math.cos(number.realPart) * Math.cosh(number.imaginaryPart), -Math.sin(number.realPart) * Math.sinh(number.imaginaryPart));
    }
    
}
