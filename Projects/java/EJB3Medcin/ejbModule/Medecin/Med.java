package Medecin;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="table_Med")
public class Med implements Serializable{
	@Id
	int id;
	String prenom;
	String nom;
	
	public Med(int id, String prenom, String nom) {
		super();
		this.id = id;
		this.prenom = prenom;
		this.nom = nom;
	}
	public Med() {
		super();
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getPrenom() {
		return prenom;
	}
	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	@Override
	public String toString() {
		return "Med [id=" + id + ", prenom=" + prenom + ", nom=" + nom + "]";
	}
	
	
}
