PRAGMA foreign_keys=ON; 

-- -----------------------------------------------------
-- Table login_account
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS login_account (
  id INTEGER PRIMARY KEY,
  email VARCHAR(100) NOT NULL,
  password VARCHAR(100) NOT NULL,
  user_type VARCHAR(20) NOT NULL,
  gender VARCHAR(10) NULL,
  date_of_birth DATE NULL,
  phone_number CHAR(12) NULL,
  account_image BLOB NULL,
  registration_date DATE NULL,
  UNIQUE (id),
  UNIQUE (email)
);


-- -----------------------------------------------------
-- Table seeker
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS seeker (
  seeker_id INTEGER NOT NULL,
  name VARCHAR(60) NOT NULL,
  CV LONGBLOB NULL,
  other_details VARCHAR(200) NULL,
  UNIQUE (seeker_id),
  PRIMARY KEY (seeker_id),
  CONSTRAINT FK_loginAccount_seeker
    FOREIGN KEY (seeker_id)
    REFERENCES login_account (id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table education_info
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS education_info (
  seeker_id INTEGER NOT NULL,
  degree_name VARCHAR(50) NOT NULL,
  major VARCHAR(50) NOT NULL,
  school_name VARCHAR(50) NOT NULL,
  gpa FLOAT NULL,
  other_details VARCHAR(200) NULL,
  PRIMARY KEY (seeker_id, degree_name, major, school_name),
  CONSTRAINT fk_education_info_seeker_prof1
    FOREIGN KEY (seeker_id)
    REFERENCES seeker (seeker_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table experience_info
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS experience_info (
  seeker_id INTEGER NOT NULL,
  company_name VARCHAR(60) NOT NULL,
  job_title VARCHAR(50) NOT NULL,
  work_address VARCHAR(150) NULL,
  start_date DATE NULL,
  end_date DATE NULL,
  other_details VARCHAR(200) NULL,
  PRIMARY KEY (seeker_id, company_name, job_title),
  CONSTRAINT fk_experience_info_seeker_prof1
    FOREIGN KEY (seeker_id)
    REFERENCES seeker (seeker_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table ref_skills
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS ref_skills (
  skill_id INTEGER PRIMARY KEY AUTOINCREMENT,
  skill_description VARCHAR(50) NOT NULL
);


-- -----------------------------------------------------
-- Table seeker_skills
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS seeker_skills (
  seeker_id INTEGER NOT NULL,
  skill_id INTEGER NOT NULL,
  PRIMARY KEY (seeker_id, skill_id),
  CONSTRAINT fk_seeker_skills_seeker_prof1
    FOREIGN KEY (seeker_id)
    REFERENCES seeker (seeker_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT FK_refSkills_seekerSkills
    FOREIGN KEY (skill_id)
    REFERENCES ref_skills (skill_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table recruiter
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS recruiter (
  recruiter_id INTEGER NOT NULL,
  name VARCHAR(60) NOT NULL,
  job_title VARCHAR(50) NOT NULL,
  from_company VARCHAR(100) NOT NULL,
  company_description VARCHAR(500) NOT NULL,
  company_image BLOB NULL,
  company_url VARCHAR(60) NULL,
  UNIQUE (recruiter_id),
  PRIMARY KEY (recruiter_id),
  CONSTRAINT recruiter_id
    FOREIGN KEY (recruiter_id)
    REFERENCES login_account (id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table vacancy
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS vacancy (
  vacancy_id INTEGER PRIMARY KEY AUTOINCREMENT,
  recruiter_id INTEGER NOT NULL,
  published_date DATE NOT NULL,
  closed_date DATE NOT NULL,
  filled_date DATE NULL,
  job_decription VARCHAR(400) NOT NULL,
  salary VARCHAR(45) NOT NULL,
  negotiable BINARY NOT NULL,
  requirements VARCHAR(400) NOT NULL,
  benefits VARCHAR(400) NULL,
  other_details VARCHAR(200) NULL,

  UNIQUE (vacancy_id),
  CONSTRAINT fk_vacancy_info_recruiter_prof1
    FOREIGN KEY (recruiter_id)
    REFERENCES recruiter (recruiter_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table vacancy_required_skills
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS vacancy_required_skills (
  vacancy_id INTEGER NOT NULL,
  skill_id INTEGER NOT NULL,
  PRIMARY KEY (vacancy_id, skill_id),
  CONSTRAINT fk_vacancy_required_skills_vacancy_info1
    FOREIGN KEY (vacancy_id)
    REFERENCES vacancy (vacancy_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT FK_refSkills_vacancySkills
    FOREIGN KEY (skill_id)
    REFERENCES ref_skills (skill_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table job_interaction
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS job_interaction (
  seeker_id INTEGER NOT NULL,
  recruiter_id INTEGER NOT NULL,
  vacancy_id INTEGER NOT NULL,
  IsApplication BINARY NOT NULL,
  PRIMARY KEY (seeker_id, recruiter_id, vacancy_id),
  CONSTRAINT fk_job_interaction_recruiter_prof1
    FOREIGN KEY (recruiter_id)
    REFERENCES recruiter (recruiter_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_job_interaction_vacancy_info1
    FOREIGN KEY (vacancy_id)
    REFERENCES vacancy (vacancy_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_job_interaction_seeker_prof1
    FOREIGN KEY (seeker_id)
    REFERENCES seeker (seeker_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table vacancy_location
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS vacancy_location (
  vacancy_id INTEGER NOT NULL,
  street_addr VARCHAR(60) NOT NULL,
  ward VARCHAR(60) NOT NULL,
  district VARCHAR(60) NOT NULL,
  city VARCHAR(60) NOT NULL,
  other_details VARCHAR(200) NULL,
  PRIMARY KEY (street_addr, ward, district, city, vacancy_id),
  CONSTRAINT fk_vacancy_location_vacancy_info1
    FOREIGN KEY (vacancy_id)
    REFERENCES vacancy (vacancy_id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table staff
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS staff (
  staff_id INTEGER NOT NULL,
  name VARCHAR(60) NOT NULL,
  job_title VARCHAR(50) NOT NULL,
  other_details VARCHAR(200) NULL,
  PRIMARY KEY (staff_id),
  CONSTRAINT FK_loginAccount_staff
    FOREIGN KEY (staff_id)
    REFERENCES login_account (id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);
