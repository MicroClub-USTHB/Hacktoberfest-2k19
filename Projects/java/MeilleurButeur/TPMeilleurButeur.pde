import java.util.Arrays;
PImage img, img1;

ArrayList<Buteur> buteurs = new ArrayList<Buteur>();
Table table;
ArrayList<Integer> listannee = new ArrayList<Integer>();

void setup(){
  
  size(1000,700);
  background(255,204,153);
  
  //define clors
  color c1,c2,c3,c4,c0;
  c0 = color(255,255,0);//jaune [1-3]
  c1 = color(51,255,255); //bleu vert [4-6]
  c2 = color(51, 255, 53); //vert [7-10]
  c3 = color(153,0,153 ); //mauve [10-13]
  c4 = color(255, 51, 51); //rouge [14-16]
 
  
  
  
 //import data
  table = loadTable("doc.csv");
  println(table.getRowCount() + " total rows in table"); 

 //split data into columns
  for (TableRow row : table.rows()) {
 
    String line = row.getString(0);
    String[] h = line.split(";");
    ArrayList<String> s = new ArrayList<String>(Arrays.asList(h));
    
    println(s.get(0) + " (" + s.get(1) + ") has an ID of " );
    buteurs.add(new Buteur(s.get(0),s.get(1),int(s.get(2)))); 
    int i;
    for (i =3;i<s.size();i+=2){
        buteurs.get(buteurs.size()-1).getDetails().add(new Details(int(s.get(i)),int(s.get(i+1))));
        if(!listannee.contains(int(s.get(i))))
            listannee.add(int(s.get(i)));
        println( buteurs.get(buteurs.size()-1).getDetails().get(buteurs.get(buteurs.size()-1).getDetails().size()-1).toString());
    }
  }
  for (int i = 0;i<buteurs.size();i++){
     println( buteurs.get(i).toString());
   
  }
  
  for (int i = 0;i<listannee.size();i++){
    println("annee ------> "+listannee.get(i));
  }
 
  ArrayList<Integer> trie =new ArrayList<Integer>();
  while(listannee.size()!=0){
    println("miiin= "+min(listannee));
    trie.add(listannee.get(min(listannee)));
    listannee.remove(min(listannee));
  }

 for (int i = 0;i<trie.size();i++){
    println("annee ------> "+trie.get(i));
  }
  ////dessin!
  
  for(float i=0;i<width;i=i+(width/(buteurs.size()+1))){
    for(float j=0;j<height;j=j+(height/(trie.size()+2))){
 
     fill(100,10,100,10);
    noStroke();
     rect(i+2,j+2,width/(buteurs.size()+1),height/(trie.size()+2),3);
    
     
     
    }
  }
  
  
  int ind=trie.size()-1; //affichage des années
    for(float j=(height/(trie.size()+2))*3;j<height;j=j+(height/(trie.size()+2))){
      textSize(20);
      fill(50);
      text("  "+trie.get(ind), 5, j+5); 
      ind--;
    }
    
    int o=0; //les buteurs et leurs infos
    
     for(int g=100;g<width;g=g+(width/(buteurs.size()+1))){
       int i=trie.size()-1;
       println("buteur:"+o);
       println("i :"+i);
         //affichage des details 
        for(float j=(height/(trie.size()+2))*3;j<height;j=j+(height/(trie.size()+2))){
          
        for(int k=0;k<buteurs.get(o).getDetails().size();k++){
        if(buteurs.get(o).getDetails().get(k).getAnnee()==trie.get(i)){
          println("ok"+buteurs.get(o).getDetails().get(k).getAnnee());
           textSize(10);
            fill(50);
      text("    "+buteurs.get(o).getDetails().get(k).getNbButs(), g, j); 
      //couleurs des ellipses selon nbbuts
      if(buteurs.get(o).getDetails().get(k).getNbButs()<4){
      fill(c0,100);
      }else if(buteurs.get(o).getDetails().get(k).getNbButs()<7){
        fill(c1,100);
      }else if(buteurs.get(o).getDetails().get(k).getNbButs()<11){
        fill(c2,100);
      }else if(buteurs.get(o).getDetails().get(k).getNbButs()<14){
        fill(c3,100);
      }else{
        fill(c4,100);
      }
      
      stroke(255);
       ellipse(g+17, j, buteurs.get(o).getDetails().get(k).getNbButs()*6, buteurs.get(o).getDetails().get(k).getNbButs()*6);
        }
        }
      
         i--; 
    }
       //Affichege nom + nation + nbButsMax
       
      textSize(18);
      fill(50);
      text(buteurs.get(o).getNomButeur()+" ", g, 25); 
      textSize(12);
      text("    "+buteurs.get(o).getNation()+"  ", g, 40);
        //couleurs des ellipses selon nbbuts
      if(buteurs.get(o).getNombreButs()<4){
      fill(c0,100);
      }else if(buteurs.get(o).getNombreButs()<7){
        fill(c1,100);
      }else if(buteurs.get(o).getNombreButs()<11){
        fill(c2,100);
      }else if(buteurs.get(o).getNombreButs()<14){
        fill(c3,100);
      }else{
        fill(c4,100);
      }
        stroke(255);
      ellipse(g+25, 70, buteurs.get(o).getNombreButs()*4, buteurs.get(o).getNombreButs()*4);
       textSize(12);
        fill(50);
      text("    "+buteurs.get(o).getNombreButs()+"  ", g, 72);
     
     
       o++;
  }
  
  
  
  /*test affichage berk
  for(int k=0;k<buteurs.size();k++){
  println(buteurs.get(k).getNomButeur());
  }*/
  
  
  
  
}
void draw(){
 
  
 
 }
 
 public int min(ArrayList<Integer>a){
   int min = 0;
   for(int i=1;i<a.size();i++){
   if(a.get(i)<a.get(min)) min=i;
   }
 return min;
 }