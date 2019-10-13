package Medecin;

import java.util.List;

import javax.ejb.Remote;

@Remote
public interface Medecin {
	  public void ajouter(Med medd);
	  public List<Med> listerTousLesvoiture();

}
