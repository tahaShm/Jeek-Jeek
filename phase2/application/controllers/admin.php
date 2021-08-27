<?php
class admin extends CI_Controller
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
    public function index()
    {
        $this->db->order_by('id', 'asc');
        $query = $this->db->get('admin');

        $data['admins'] = $query->result_array();
        $this->load->view('admin', $data);

    }
    public function sign_admin()
    {
        $_SESSION['user_login'] ='';
        $data['name'] = $this->input->post('name');
        $data['password'] = $this->input->post('password');
        $this->db->where('name', $data['name']);
        $this->db->where('password', $data['password']);
        $query = $this->db->get('admin');
        $result = $query->result_array();


        if (@$result[0]['name'] != '') {
            $data1['admins'] = $result;
            $_SESSION['check'] = 'ok';
            $_SESSION['user_login'] =$this->input->post('name');;



            $this->load->view('admin_in', $data1);

        } else {
            $_SESSION['user_login'] ='';
            $query = $this->db->get('admin');
            $data1['admins'] = $query->result_array();
            $_SESSION['check'] = 'err';
            $this->load->view('admin', $data1);
        }
    }

    public function insert()
    {
            $this->db->order_by('id', 'asc');
            $data['title'] = $this->input->post('title');
            $data['pretext'] = $this->input->post('pretext');
            $data['text'] = $this->input->post('text');
            $data['topic'] = $this->input->post('topic');
            if ($data['title'] != '' && $data['text'] != '' && $data['pretext'] != '') {
                $config['upload_path'] = './files/';
                $config['allowed_types'] = 'gif|jpg|png';
                $config['max_size'] = 1000000;
                $config['file_name'] = time();

                $this->load->library('upload', $config);

                $ext = pathinfo($_FILES['image']['name'], PATHINFO_EXTENSION);

                if ($this->upload->do_upload('image')) {

                    $data['image'] = '../files/' . $config['file_name'] . '.' . $ext;

                }
                $this->db->insert('content', $data);
            }
            header('Location: ' . base_url() . 'admin/article');
    }
    public function article()
    {
            $this->db->order_by('id', 'asc');
            $query = $this->db->get('content');
            $data1['contents'] = $query->result_array();
            $this->load->view('insert_article', $data1);
    }
    public function update($id)
    {
        $this->db->where('id' , $id);
        $query =$this->db->get('content');
        $data['contents'] = $query->result_array();

        $this->load->view('edit_article' , $data);
    }

    public function edit()
    {
        $id = $this->input->post('id');
        $data['title'] = $this->input->post('title');
        $data['pretext'] = $this->input->post('pretext');
        $data['text'] = $this->input->post('text');
        $data['topic'] = $this->input->post('topic');

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
        $this->db->update('content',$data);

        $this->db->order_by('id' , 'asc');
        $query = $this->db->get('content');
        $data1['contents'] = $query->result_array();
        $this->load->view('insert_article' , $data1);
    }
    public function delete()
    {
        $id = $this->input->post('id');
        $data['id'] = $id;
        $this->db->delete('content', $data);

        $this->db->order_by('id' , 'asc');
        $query =$this->db->get('content');
        $data['contents'] = $query->result_array();
    }
    public function insert_user()
    {
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
            header('Location: ' . base_url() . 'admin/user');
    }
    public function user()
    {
            $this->db->order_by('id', 'asc');
            $query = $this->db->get('user');
            $data1['users'] = $query->result_array();
            $this->load->view('insert_user', $data1);
    }
    public function update_user($id)
    {

        $this->db->where('id' , $id);
        $query =$this->db->get('user');
        $data['users'] = $query->result_array();

        $this->load->view('edit_user' , $data);
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
        $this->load->view('insert_user' , $data1);
    }
    public function delete_user()
    {
        $id = $this->input->post('id');
        $data['id'] = $id;
        $this->db->delete('user', $data);

        $this->db->order_by('id' , 'asc');
        $query =$this->db->get('user');
        $data['users'] = $query->result_array();
    }
    public function showing()
    {
        $showing = $this->input->post('showing');
        $id = $this->input->post('id');

        $data['showing'] = $showing;
        if( $data['showing']==1){
            $data['showing']=0;
        }
        else{
            $data['showing']=1;
        }
        $this->db->where('id' , $id);
        $this->db->update('content',$data);
        return $data['showing'];
    }
}