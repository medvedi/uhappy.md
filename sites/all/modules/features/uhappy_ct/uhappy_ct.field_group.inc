<?php
/**
 * @file
 * uhappy_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhappy_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_children_settings|node|scenario|form';
  $field_group->group_name = 'group_children_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scenario';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Children settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_age_range',
      1 => 'field_children_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Children settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-children-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_children_settings|node|scenario|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom|node|scenario|form';
  $field_group->group_name = 'group_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scenario';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom',
    'weight' => '12',
    'children' => array(
      0 => 'field_custom_html',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-custom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_custom|node|scenario|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom|node|slider|form';
  $field_group->group_name = 'group_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slider';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom',
    'weight' => '1',
    'children' => array(
      0 => 'field_custom_html',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-custom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_custom|node|slider|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data|node|order|form';
  $field_group->group_name = 'group_personal_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal data',
    'weight' => '7',
    'children' => array(
      0 => 'field_phone_number',
      1 => 'field_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-personal-data field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal_data|node|order|form'] = $field_group;

  return $export;
}
