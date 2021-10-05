public class Temperatura {
    private float gradi_centigradi;
    private float gradi_fahrenheit;

    public void setGradiC(float gradi_centigradi) throws Exception{
        if(gradi_centigradi<-273.15){
            throw new Exception("temperatura non valida");
        }
        else{
            this.gradi_centigradi=gradi_centigradi;
        }
    }

    public float getGradiC(){
        return this.gradi_centigradi;
    }

    public float getGradiF(){
        this.gradi_fahrenheit=(gradi_centigradi*9/5)+32;
        return this.gradi_fahrenheit;
    }

}
