public class Buteur{
  
 String NomButeur;
 String Nation;
 int NombreButs;

ArrayList<Details> DetailButeur =new ArrayList<Details>();

Buteur (){

}

Buteur(String nom, String Nation, int nbut){
  this.NomButeur = nom;
  this.Nation=Nation;
  this.NombreButs=nbut;
  DetailButeur = new ArrayList<Details>();
}

public void setNation(String nation){
this.Nation=nation;
}

public String getNation(){
return this.Nation;
}

public void setNomButeur(String nom){
this.NomButeur=nom;
}

public String getNomButeur(){
return this.NomButeur;
}

public void SetNombreButs(int nb){
this.NombreButs=nb;
}



public int getNombreButs(){
  return this.NombreButs;
}

public ArrayList<Details> getDetails(){
    return DetailButeur;
}

public String toString(){
  String s = "";
  for (int i = 0;i<DetailButeur.size();i++)
  s = s+"\t"+DetailButeur.get(i).getAnnee()+" --> "+DetailButeur.get(i).getNbButs();
  return "Nom : "+this.NomButeur+"  dont la nationnalité est "+Nation+" a inscrit "+NombreButs+"  buts au Total \n\t "+s;
}


}