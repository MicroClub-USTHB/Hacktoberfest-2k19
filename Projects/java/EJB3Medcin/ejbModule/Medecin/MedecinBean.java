package Medecin;

import java.util.ArrayList;
import java.util.List;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class MedecinBean implements Medecin{
	@PersistenceContext
	EntityManager em;

	public void ajouter(Med medd) {
		// TODO Auto-generated method stub
		em.persist(medd);

	}

	public List<Med> listerTousLesvoiture() {
		// TODO Auto-generated method stub
		   return em.createQuery("SELECT p FROM Med p ").getResultList();

	}

}
