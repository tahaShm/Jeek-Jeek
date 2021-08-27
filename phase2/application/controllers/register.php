<?php
class register extends CI_Controller
{
    public function __construct()
    {
        parent::__construct();
        $this->load->helper(array('form', 'url'));
        $this->load->database();
        $this->load->model('connect');
        $this->load->library('session');
        $this->load->helper('form');
    }
    public function insert_user()
    {
        $_SESSION['register']='';
        $this->db->order_by('id', 'asc');
        $data['name'] = $this->input->post('name');
        $data['lname'] = $this->input->post('lname');
        $data['password'] = $this->input->post('password');
        if ($data['name'] != '' && $data['lname'] != '' && $data['password']!= '') {
            $config['upload_path'] = './files/';
            $config['allowed_types'] = 'gif|jpg|png';
            $config['max_size'] = 1000000;
            $config['file_name'] = time();

            $this->load->library('upload', $config);

            $ext = pathinfo($_FILES['image']['name'], PATHINFO_EXTENSION);

            if ($this->upload->do_upload('image')) {

                $data['image'] = '../files/' . $config['file_name'] . '.' . $ext;

            }
            $this->db->insert('user', $data);

        }
        header('Location: ' . base_url() . 'register/user');
    }
    public function user()
    {
        $this->db->order_by('id', 'asc');
        $query = $this->db->get('user');
        $data1['users'] = $query->result_array();
        $_SESSION['register']=$this->input->post('name');
        $this->load->view('register', $data1);
    }
    public function login()
    {
        $data['name'] = $this->input->post('name');
        $data['lname'] = $this->input->post('lname');
        $data['password'] = $this->input->post('password');
        $this->db->where('name' , $data['name']);
        $this->db->where('lname' , $data['lname']);
        $this->db->where('password' , $data['password']);
        $query = $this->db->get('user');
        $result = $query->result_array();


        if(@$result[0]['name'] != ''){
            $_SESSION['Username'] = $data['name'];
            $data1['users'] = $result;
            $this->load->view('user_page' , $data1);
        }else{
            $query = $this->db->get('user');
            $data1['users'] = $query->result_array();
            $this->load->view('login' , $data1);
        }


    }
    public function update_user($id)
    {

        $this->db->where('id' , $id);
        $query =$this->db->get('user');
        $data['users'] = $query->result_array();

        $this->load->view('user_page_edit' , $data);
    }

    public function edit_user()
    {
        $id = $this->input->post('id');
        $data['name'] = $this->input->post('name');
        $data['lname'] = $this->input->post('lname');
        $data['password'] = $this->input->post('password');
        if($_FILES['image']['name'] != ''){
            $config['upload_path'] = './files/';
            $config['allowed_types'] = 'gif|jpg|png';
            $config['max_size'] = 1000000;
            $config['file_name'] = time();

            $this->load->library('upload', $config);

            $ext = pathinfo($_FILES['image']['name'], PATHINFO_EXTENSION);

            if ($this->upload->do_upload('image')) {

                $data['image'] = '../files/' . $config['file_name'] . '.' . $ext;

            }
        }

        $this->db->where('id' , $id);
        $this->db->update('user',$data);

        $this->db->order_by('id' , 'asc');
        $query = $this->db->get('user');
        $data1['users'] = $query->result_array();
        $this->load->view('user_page' , $data1);
    }

}