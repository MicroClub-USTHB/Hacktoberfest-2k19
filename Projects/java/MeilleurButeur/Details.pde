public class Details{

  int annee ;
  int NombreButs;
  
  public Details(int annee ,int NombreButs){
  this.annee=annee;
  this.NombreButs=NombreButs;
  }
  
public void setAnnee(int annee){
  this.annee=annee;
}

public int getAnnee(){
return this.annee;
}

 public void setNbButs(int nb){
  this.NombreButs =nb;
}

public int getNbButs(){
return this.NombreButs;
}

public String toString(){
  return "" + this.annee +" --> "+this.NombreButs;
}

}