<?php
/**
 * @file
 * uhappy_views_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function uhappy_views_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'blog_panel_context';
  $handler->task = 'blog';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Blog list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocolumnfound';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one' => NULL,
      'two' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '80afa0cb-f6ee-41e6-8ca7-c026e08b7ecf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67cf0c4a-737a-49c8-ab2f-d7e917df09ba';
    $pane->panel = 'one';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_api_views-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '67cf0c4a-737a-49c8-ab2f-d7e917df09ba';
    $display->content['new-67cf0c4a-737a-49c8-ab2f-d7e917df09ba'] = $pane;
    $display->panels['one'][0] = 'new-67cf0c4a-737a-49c8-ab2f-d7e917df09ba';
    $pane = new stdClass();
    $pane->pid = 'new-e778a74b-1b2f-4552-994f-0ff8fc1ccbef';
    $pane->panel = 'two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-u9JuTvOWug0UlH84myHDETD5bBYN0v9U';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Scenarion',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e778a74b-1b2f-4552-994f-0ff8fc1ccbef';
    $display->content['new-e778a74b-1b2f-4552-994f-0ff8fc1ccbef'] = $pane;
    $display->panels['two'][0] = 'new-e778a74b-1b2f-4552-994f-0ff8fc1ccbef';
    $pane = new stdClass();
    $pane->pid = 'new-8b991871-f055-49d2-afbc-c9c687ed4ebf';
    $pane->panel = 'two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-IPaCM7H1dF7Clj1WBtiZQw516MCvTYka';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Categories',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8b991871-f055-49d2-afbc-c9c687ed4ebf';
    $display->content['new-8b991871-f055-49d2-afbc-c9c687ed4ebf'] = $pane;
    $display->panels['two'][1] = 'new-8b991871-f055-49d2-afbc-c9c687ed4ebf';
    $pane = new stdClass();
    $pane->pid = 'new-3a11dda7-8018-41a3-b50c-0c16f407b7fe';
    $pane->panel = 'two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-006i2ydH3VyJuB1m9c18xr81tXcAwDVN';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Archive',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3a11dda7-8018-41a3-b50c-0c16f407b7fe';
    $display->content['new-3a11dda7-8018-41a3-b50c-0c16f407b7fe'] = $pane;
    $display->panels['two'][2] = 'new-3a11dda7-8018-41a3-b50c-0c16f407b7fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['blog_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'blog_user_panel_context';
  $handler->task = 'blog_user';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User blog',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocolumnfound';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one' => NULL,
      'two' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fea3239e-252e-4fb9-94c1-3c4d6fd86840';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cae9b465-c790-48b3-acec-8a6f3cfbd62c';
    $pane->panel = 'one';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_list-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cae9b465-c790-48b3-acec-8a6f3cfbd62c';
    $display->content['new-cae9b465-c790-48b3-acec-8a6f3cfbd62c'] = $pane;
    $display->panels['one'][0] = 'new-cae9b465-c790-48b3-acec-8a6f3cfbd62c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cae9b465-c790-48b3-acec-8a6f3cfbd62c';
  $handler->conf['display'] = $display;
  $export['blog_user_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Node view',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'af9355d9-d3ed-48e7-8932-b5ae4a4359ad';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b74d40e0-983d-453a-bd8c-154d5b990e77';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b74d40e0-983d-453a-bd8c-154d5b990e77';
    $display->content['new-b74d40e0-983d-453a-bd8c-154d5b990e77'] = $pane;
    $display->panels['middle'][0] = 'new-b74d40e0-983d-453a-bd8c-154d5b990e77';
    $pane = new stdClass();
    $pane->pid = 'new-50128e6d-9d01-43bd-9e9d-8e288744e599';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'content_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '50128e6d-9d01-43bd-9e9d-8e288744e599';
    $display->content['new-50128e6d-9d01-43bd-9e9d-8e288744e599'] = $pane;
    $display->panels['middle'][1] = 'new-50128e6d-9d01-43bd-9e9d-8e288744e599';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-b74d40e0-983d-453a-bd8c-154d5b990e77';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '16522c22-8f08-4c5b-995c-e48d95113667';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0e66aad4-8753-4cd4-b80c-8db4c23ff905';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'content_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0e66aad4-8753-4cd4-b80c-8db4c23ff905';
    $display->content['new-0e66aad4-8753-4cd4-b80c-8db4c23ff905'] = $pane;
    $display->panels['center'][0] = 'new-0e66aad4-8753-4cd4-b80c-8db4c23ff905';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function uhappy_views_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fronpage';
  $page->task = 'page';
  $page->admin_title = 'Fronpage';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fronpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'fronpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '11dcde6d-0b12-4e24-a47d-2dc8de1474cd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-88c499d3-bebc-4d05-b9cc-cb3eae4f2422';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '88c499d3-bebc-4d05-b9cc-cb3eae4f2422';
    $display->content['new-88c499d3-bebc-4d05-b9cc-cb3eae4f2422'] = $pane;
    $display->panels['middle'][0] = 'new-88c499d3-bebc-4d05-b9cc-cb3eae4f2422';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fronpage'] = $page;

  return $pages;

}
